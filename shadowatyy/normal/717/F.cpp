#include <bits/stdc++.h>
#define ll long long
const ll INF = 1e18L+7;
using namespace std;

#define int ll
const int N = 1<<18;

int n, q;

set<int> zeros;

int x[N];

struct tree
{
    int Min[2*N];
    int Max[2*N];
    int load[2*N];

    void update(int v, int c)
    {
        Min[v] += c;
        Max[v] += c;
        load[v] += c;
    }

    void merge(int v)
    {
        Min[v] = min(Min[2*v], Min[2*v+1]);
        Max[v] = max(Max[2*v], Max[2*v+1]);
        Min[v] += load[v];
        Max[v] += load[v];
    }

    void insert(int a, int b, int c, int v = 1, int l = 0, int r = N-1)
    {
        if(a>r || l>b)
            return;

        if(a<=l && r<=b)
        {
            update(v, c);
            return;
        }

        insert(a, b, c, 2*v, l, (l+r)/2);
        insert(a, b, c, 2*v+1, (l+r)/2+1, r);
        merge(v);
    }

    int queryMin(int a, int b, int v = 1, int l = 0, int r = N-1)
    {
        if(a>r || l>b)
            return INF;

        if(a<=l && r<=b)
            return Min[v];

        return load[v]+min(queryMin(a, b, 2*v, l, (l+r)/2), queryMin(a, b, 2*v+1, (l+r)/2+1, r));
    }

    int queryMax(int a, int b, int v = 1, int l = 0, int r = N-1)
    {
        if(a>r || l>b)
            return -INF;

        if(a<=l && r<=b)
            return Max[v];

        return load[v]+max(queryMax(a, b, 2*v, l, (l+r)/2), queryMax(a, b, 2*v+1, (l+r)/2+1, r));
    }
}P, NP;

void dodajP(int a, int b, int c)
{
    if(b%2!=0)
        --b;

    b /= 2;

    if(a%2!=0)
        ++a;

    a /= 2;
    P.insert(a, b, c);
}

void dodajNp(int a, int b, int c)
{
    if(b%2!=1)
        --b;

    b /= 2;

    if(a%2!=1)
        ++a;

    a /= 2;
    NP.insert(a, b, c);
}

int pytajMinP(int a, int b)
{
    if(b%2!=0)
        --b;

    b /= 2;

    if(a%2!=0)
        ++a;

    a /= 2;
    return P.queryMin(a, b);
}

int pytajMinNp(int a, int b)
{
    if(b%2!=1)
        --b;

    b /= 2;

    if(a%2!=1)
        ++a;

    a /= 2;
    return NP.queryMin(a, b);
}

int pytajMaxP(int a, int b)
{
     if(b%2!=0)
        --b;

    b /= 2;

    if(a%2!=0)
        ++a;

    a /= 2;
    return P.queryMax(a, b);
}

int pytajMaxNp(int a, int b)
{
    if(b%2!=1)
        --b;

    b /= 2;

    if(a%2!=1)
        ++a;

    a /= 2;
    return NP.queryMax(a, b);
}

void wypisz()
{
     for(int i = 0; i < n; ++i)
        {
            if(i%2)
                cout << pytajMaxNp(i, i) << " ";
            else
                cout << pytajMaxP(i, i) << " ";
        }

        cout << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n;

    for(int i = 0; i < n; ++i)
    {
        cin >> x[i];

        if(!x[i])
            zeros.insert(i);

        --x[i];

        if(i%2)
            x[i] = -x[i] + x[i-1];
        else
            x[i] = x[i] + x[i-1];

        if(i%2==0)
            dodajP(i, i, x[i]);
        else
            dodajNp(i, i, x[i]);
    }

    cin >> q;

    while(q--)
    {
        int t;
        cin >> t;

        if(t==1)
        {
            int a, b, k;
            cin >> a >> b >> k;

            if(k>0)
            {
                auto curr = zeros.lower_bound(a);

                while(curr!=zeros.end() && *curr<=b)
                {
                    int ind = *curr;
                    curr = zeros.upper_bound(ind);
                    zeros.erase(ind);
                }
            }

            if(a%2==0)
                dodajP(a, b, k);
            else
                dodajNp(a, b, -k);

                //wypisz();

            if(a%2==b%2)
            {
                if(a%2==0)
                {
                    dodajP(b+1, n-1, k);
                    dodajNp(b+1, n-1, k);
                }
                else
                {
                    dodajP(b+1, n-1, -k);
                    dodajNp(b+1, n-1, -k);
                }
            }

            // wypisz();
        }
        else
        {
            int a, b;
            cin >> a >> b;

            int przed = -1;

            if(a==0)
                przed = 0;
            else if((a-1)%2)
                przed = pytajMinNp(a-1, a-1);
            else
                przed = pytajMinP(a-1, a-1);

            bool ans = 1;

            if(zeros.lower_bound(a)!=zeros.end() && *zeros.lower_bound(a)<=b)
                ans = 0;

            if(pytajMinP(a, b)<przed)
                ans = 0;

            if(pytajMaxNp(a, b)>przed)
                ans = 0;

            if(b%2==0 && pytajMinP(b, b)!=przed)
                ans = 0;

            if(b%2==1 && pytajMinNp(b, b)!=przed)
                ans = 0;

            cout << ans << endl;
        }
    }
}