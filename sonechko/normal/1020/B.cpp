#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 3e5 + 11;

int a[N],use[N];

int dfs(int l)
{
    if (use[l]==1) return l;
    use[l]=1;
    dfs(a[l]);
}

int main()
{
   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   int n;
   cin>>n;
   for (int i=1; i<=n; i++)
    cin>>a[i];
   for (int i=1; i<=n; i++)
   {
       for (int j=1; j<=n; j++)
        use[j]=0;
       cout<<dfs(i)<<" ";
   }
}