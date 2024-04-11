#include <bits/stdc++.h>
#define ll long long
#define st first
#define nd second
#define VI vector<int>
#define pb push_back
using namespace std;

#define cerr if(0)cout
const int N = 1<<16;

int mod;

struct mat
{
    int m[2][2];

    mat()
    {
        m[0][0] = m[1][1] = m[0][1] = m[1][0]  = 0;
    }
}I, all;

mat operator * (mat A, mat B)
{
    mat C;

    for(int i = 0; i < 2; ++i)
    {
        for(int k = 0; k < 2; ++k)
        {
            for(int j = 0; j < 2; ++j)
            {
                C.m[i][j] += (ll)A.m[i][k]*B.m[k][j]%mod;

                if(C.m[i][j]>=mod)
                    C.m[i][j] -= mod;
            }
        }
    }

    return C;
}

mat fpow(mat A, ll p)
{
    mat ans = I;

    while(p)
    {
        if(p&1)
            ans = ans * A;

        A = A * A;
        p /= 2;
    }

    return ans;
}

mat load[2*N];

int n, m;

ll k;

int s[N];

map<ll, int> M;

//vector<pair<int, int> > vec;

int get(ll x)
{
    if(M.count(x))
        return M[x];
    else
        return s[x%n];
}

mat getMat(ll x)
{
    mat ans;
    ans.m[0][0] = get(x+1);
    ans.m[0][1] = get(x);
    ans.m[1][0] = 1;
    return ans;
}

void build(int v = 1, int l = 0, int r = N-1)
{
    if(l==r)
    {
        load[v].m[0][0] = s[(l+1)%n];
        load[v].m[0][1] = s[l%n];
        load[v].m[1][0] = 1;
        return;
    }

    build(2*v, l, (l+r)/2);
    build(2*v+1, (l+r)/2+1, r);
    load[v] = load[2*v+1] * load[2*v];
}

mat query(int a, int b, int v = 1, int l = 0, int r = N-1)
{
    if(a>r || l>b)
        return I;

    if(a<=l && r<=b)
        return load[v];

    return  query(a, b, 2*v+1, (l+r)/2+1, r) * query(a, b, 2*v, l, (l+r)/2);
}

mat seg(ll a, ll b)
{
    cerr << a << " " << b << endl;

    /*mat ans = I;

    for(int i = a; i <= b; ++i)
        ans = getMat(i) * ans;

    return ans;*/

    if(a<=b && a/n==b/n)
        return query(a%n, b%n);

    int lewo = n-a%n;
    int prawo = b%n+1;
    ll ile = (b-a+1 - lewo - prawo) / n;
    cerr << a << " " << b << " " << ile << " " << lewo << " " << prawo << endl;
    return  query(0, b%n) * fpow(all, ile) * query(a%n, n-1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    I.m[0][0] = I.m[1][1] = 1;

    cin >> k >> mod >> n;

    if(k==0)
    {
        cout << 0 << endl;
        return 0;
    }

    if(k==1)
    {
        cout << 1%mod << endl;
        return 0;
    }

    k -= 2;

    for(int i = 0; i < n; ++i)
    {
        cin >> s[i];
    }

    cin >> m;

    for(int i = 0; i < m; ++i)
    {
        ll x;
        int val;
        cin >> x >> val;
        M[x] = val;
        //vec.emplace_back(x, val);
    }

   // sort(vec.begin(), vec.end());

    //while(!vec.empty() && vec.back().st>k+1)
     //   vec.pop_back();

    build();
    all = query(0, n-1);
    mat ans = I;

    ll curr = -1;

    while(curr<k)
    {
        auto it = M.lower_bound(curr+1);

        if(it==M.end())
        {
            ans = seg(curr+1, k) * ans;
            break;
        }

        if(it->st > curr+2)
        {
            ll dokad = min(k, it->st - 2);
            ans = seg(curr+1, dokad) * ans;
            curr = dokad;
        }
        else
        {
            cerr << curr+1 << endl;
            ans = getMat(curr+1) * ans;
            ++curr;
        }
    }

    cout << ans.m[0][0]%mod << endl;
}