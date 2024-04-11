#include<bits/stdc++.h>
using namespace std;
long long mod = 1e6+3;
long long P(long long a,long long b)
{
    if (b==0)return 1;
    long long x = P(a,b/2);
    x = (x*x)%mod;
    if (b%2) x = (x*a)%mod;
    return x;
}
long long inv(long long x)
{
    return P(x,mod-2);
}
// Gauss-Jordan elimination.
// Returns: number of solution (0, 1 or INF)
//   When the system has at least one solution, ans will contains
//   one possible solution
// Possible improvement when having precision errors:
//   - Divide i-th row by a(i, i)
//   - Choosing pivoting row with min absolute value (sometimes this is better that maximum, as implemented here)
// Tested:
// - https://open.kattis.com/problems/equationsolver
// - https://open.kattis.com/problems/equationsolverplus
long long gauss (vector < vector<long long> > a, vector<long long> & ans) {
    long long n = (long long) a.size();
    long long m = (long long) a[0].size() - 1;

    vector<long long> where (m, -1);
    for (long long col=0, row=0; col<m && row<n; ++col) {
        long long sel = row;
        for (long long i=row; i<n; ++i)
            if (a[i][col] > a[sel][col])
                sel = i;
        if (a[sel][col]==0)
            continue;
        for (long long i=col; i<=m; ++i)
            swap (a[sel][i], a[row][i]);
        where[col] = row;

        for (long long i=0; i<n; ++i)
            if (i != row) {
                long long c = a[i][col] * inv(a[row][col]);
                c%=mod;
                for (long long j=col; j<=m; ++j)
                    a[i][j] -= (a[row][j] * c)%mod,a[i][j]=(a[i][j]+mod)%mod;
            }
        ++row;
    }

    ans.assign (m, 0);
    for (long long i=0; i<m; ++i)
        if (where[i] != -1)
            ans[i] = (a[where[i]][m] * inv(a[where[i]][i]))%mod;
    for (long long i=0; i<n; ++i) {
        long long sum = 0;
        for (long long j=0; j<m; ++j)
            sum += (ans[j] * a[i][j])%mod,sum%=mod;
        if ((sum - a[i][m])!=0)
            return 0;
    }
}

set<int> s;
int main()
{
    vector<vector<long long> > vec;
    for (int j=0;j<49;j++)
    {
        int i = (rand()*1LL*rand()+rand())%mod;
        cout<<"? "<<i<<endl;
        long long x;
        cin>>x;
        if (x==0)
        {
            cout<<"! "<<i<<endl;
            return 0;
        }
        vector<long long> g;
        for (int k=0;k<=10;k++)
            g.push_back(P(i,k));
        g.push_back(x);
        vec.push_back(g);
    }
    vector<long long> sol;
    int r = gauss(vec,sol);
    if (r==0)
    {
        cout<<"! -1"<<endl;
        return 0;
    }
    for (int i=0;i<mod;i++)
    {
        long long x = i;
        long long val = 0;
        for (int o=0;o<=10;o++)
            val+=(P(x,o)*sol[o])%mod,val%=mod;
        if (val==0)
        {
            cout<<"! "<<x<<endl;
            return 0;
        }
    }
    cout<<"! -1"<<endl;
    return 0;
}