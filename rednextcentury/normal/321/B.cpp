# include<bits/stdc++.h>
using namespace std;
int A[1000];
int D[1000];
int S[1000];
bool vis[10000];
int main()
{
    int n,m;
    cin>>n>>m;
    swap(n,m);
    int tot1=0,tot2=0;
    for (int i=0;i<m;i++)
    {
        string x;
        int val;
        cin>>x>>val;
        if (x=="ATK")
            A[tot1++]=val;
        else
            D[tot2++]=val;
    }
    for (int i=0;i<n;i++)
    {
        int val;
        cin>>val;
        S[i]=val;
    }
    sort(A,A+tot1);
    sort(D,D+tot2);
    sort(S,S+n);
    int ans=0;
    int cur=0;
    int i=0,j=n-1;
    while(i<tot1 && j>=0)
    {
        if (A[i]<S[j])
            cur+=S[j]-A[i];
        else
            break;
        i++,j--;
    }
    ans=max(ans,cur);
    j=0;
    for (i=0;i<n;i++)
    {
        if (j==tot2)
            break;
        if (S[i]>D[j])
            vis[i]=1,j++;
    }
    if (j==tot2)
    {
        j=0;
        cur=0;
        for (i=0;i<n;i++)
        {
            while(vis[i])i++;
            if (j==tot1)
                cur+=S[i],vis[i]=1;
            else if (S[i]>=A[j])
                cur+=S[i]-A[j],j++,vis[i]=1;
        }
for (i=0;i<n;i++)
        {
            if (!vis[i] && j==tot1) cur+=S[i];
        }
        if (j==tot1)
            ans=max(ans,cur);
    }
    cout<<ans<<endl;
}