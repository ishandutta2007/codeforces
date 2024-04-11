//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int n, a[301], b[301];
int cnt, ans[1000001];

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        int k;
        for(int j=i;j<=n;j++)
        {
        	if(b[j] == a[i])
			{
				k = j;
				break;
			}
		}
        for(int j=k;j>=i+1;j--)
        {
            swap(b[j-1], b[j]);
            ans[++cnt] = j;
        }
    }
    cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++) cout<<ans[i]-1<<" "<<ans[i]<<endl;
    return 0;
}