#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const ll MOD = 1e9 + 7, N = 1e5 + 11;
#define mod %MOD
int l[N],r[N],use[N],ans,n;
void dfs(int k)
{
    use[k]=1;
    for (int i=1; i<=n; i++)
    if (use[i]==0&&(l[i]==l[k]||r[i]==r[k])) dfs(i);
}
int main()
{
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>l[i]>>r[i];
    }
    for (int i=1; i<=n; i++)
    if (use[i]==0) {ans++; dfs(i);}
    cout<<ans-1<<endl;
}