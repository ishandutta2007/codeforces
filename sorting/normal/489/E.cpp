#include<bits/stdc++.h>

using namespace std;

const long long N = 1007;
const long double eps = 1E-10;

long long x[N], b[N];
long double dp[N];
int where[N];

bool solve(long double ratio, long long n, long long len)
{
    dp[n] = (long double) 0.0;
    
    for(long long pos = n-1; pos >= 0; pos--)
    {
        dp[pos] = (long double)(sqrt(fabs(x[n] - x[pos] - len)) - ratio * b[n]) + dp[n];
        where[pos] = n;
        
        for(long long i = pos+1; i < n; i++)
        {
            long double d = (long double)(sqrt(fabs(x[i] - x[pos] - len)) - ratio * b[i]) + dp[i]; 
            
            if((long double)d < dp[pos])
            {
                dp[pos] = d;
                where[pos] = i;
            } 
        }
    }
    
    if(dp[0] >= (long double)0.0)
        return 1;
        
    return 0;
}

void bin_search(long long n, long long len)
{
    long double l = 0, r = 1000000, mid;
    
    while(r - l > eps)
    {
        mid = (long double)(l+r) / 2.0;
        
        if(solve(mid, n, len) )
            l = mid;
        else
            r = mid;

        //cout << l << " " << r << endl; 
    }  
    long double ratio = l;

    solve(ratio, n, len);

    long long curr = 0;

    while(curr != n)
    {
        if(curr)
            cout << curr << " ";
        curr = where[curr];
    }

    cout << curr << "\n";

    return ;
}

int main ()
{
    long long n, len;
    
    cin >> n >> len;
    
    for(int i = 1; i <= n; i++)
        cin >> x[i] >> b[i];
        
    x[0] = 0;
    b[0] = 0;
    
    bin_search(n, len);
    
    return 0;
}