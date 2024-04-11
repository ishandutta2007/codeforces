#include <bits/stdc++.h>
using namespace std;
int mnR[30];
int mxR[30];
int mnC[30];
int mxC[30];
pair<int,int> snake[100];
char a[2001][2001];
char b[2001][2001];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        int mx=-1;
        int locX=-1,locY=0;
        for (int i=0;i<=26;i++)
            mnR[i]=1e6,mnC[i]=1e6,mxR[i]=-1,mxC[i]=-1;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                char x;
                cin>>x;
                a[i][j]=x;
                b[i][j]='.';
                if (x>='a' && x<='z')
                {
                    int id = x-'a';
                    mnR[id]=min(mnR[id],i);
                    mnC[id]=min(mnC[id],j);
                    mxR[id]=max(mxR[id],i);
                    mxC[id]=max(mxC[id],j);
                    if (id>mx)mx=id,locX=i,locY=j;
                }
            }
        }
        if (locX==-1) {
            cout<<"YES"<<endl;
            cout<<0<<endl;
            continue;
        }
        bool ok=1;
        for (int i=0;i<=mx;i++) {
            if (mxR[i]==-1) {
                mnR[i]=locX;
                mxR[i]=locX;
                mnC[i]=locY;
                mxC[i]=locY;
            }
            if (mnR[i]!=mxR[i] && mnC[i]!=mxC[i])
                ok=0;
            for (int r=mnR[i];r<=mxR[i];r++) {
                for (int c=mnC[i];c<=mxC[i];c++) {
                    b[r][c]=char(i+'a');
                }
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (a[i][j]!=b[i][j])
                    ok=0;
                if (!ok)break;
            }
            if (!ok)break;
        }
        if (ok){
            cout<<"YES"<<endl;
            cout<<mx+1<<endl;
            for (int i=0;i<=mx;i++)
                cout<<mnR[i]+1<<' '<<mnC[i]+1<<' '<<mxR[i]+1<<' '<<mxC[i]+1<<endl;
        } else {
            cout<<"NO"<<endl;
        }

    }
}