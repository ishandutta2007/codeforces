#include<bits/stdc++.h>
using namespace std;
#define ll long long
int x[100];
int y[100];
int ok[1001][1001];
int gx[100];
int gy[100];
int mv[][2]={{0,1},{1,0},{-1,0},{0,-1}};
bool needs[1000];
int n;
vector<pair<pair<int,int>,pair<int,int> > > vec;
void move(int i,int d) {
    int x1=x[i],y1=y[i];
    int x2=x[i]+mv[d][0],y2=y[i]+mv[d][1];
    vec.push_back({{x1,y1},{x2,y2}});
    x[i]=x2;
    y[i]=y2;
    swap(ok[x1][y1],ok[x2][y2]);
}
void Take(int i)
{
    while(y[i]>1)move(i,3);
    while(x[i]>1)move(i,2);
    while(y[i]<n && ok[x[i]][y[i]+1]==0)move(i,0);
}
vector<pair<pair<int,int>,int> > ord;
int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m;
    cin>>n>>m;
    for (int i=1;i<=m;i++)
        cin>>x[i]>>y[i],ok[x[i]][y[i]]=i;
    for (int i=1;i<=m;i++) {
        cin >> gx[i] >> gy[i];
        ord.push_back({{gx[i],gy[i]},i});
    }
    sort(ord.begin(),ord.end());
    if (n==1){
        printf("0\n");return 0;
    }
    for (int i=n;i>=1;i--) {
        if (!ok[1][i])continue;
        int j=i;
        while(j<n && ok[1][j+1]==0)move(ok[1][j],0),j++;
    }
    for (int i=2;i<=2;i++)
        for (int j=1;j<=n;j++)
            if (ok[i][j])
                Take(ok[i][j]);
    for (int i=3;i<=n;i++) {
        for (int j=1;j<=n;j++) {
            if (ok[i][j]) {
                int v = ok[i][j];
                while(x[v]>2)move(v,2);
                int empt = 1;
                while(ok[1][empt])empt++;
                while(y[v]>empt)move(v,3);
                while(y[v]<empt)move(v,0);
                move(v,2);
            }
        }
    }
    for (int i=0;i<ord.size();i++) {
        int v = ord[i].second;
        for (int l=0;l<i;l++)move(v,1);
    }
    int cur = n;
    for (int i=ord.size()-1;i>=0;i--) {
        int v = ord[i].second;
        while(y[v]<cur)move(v,0);
        while(y[v]>cur)move(v,3);
        cur--;
    }
    for (int i=0;i<ord.size();i++) {
        int v = ord[i].second;
        while(x[v]<gx[v])move(v,1);
        while(x[v]>gx[v])move(v,2);
        while(y[v]>1 && ok[x[v]][y[v]-1]==0)move(v,3);
    }
    for (int i=ord.size()-1;i>=0;i--) {
        int v = ord[i].second;
        while(y[v]<gy[v])move(v,0);
    }

    // assert(vec.size()<=10800);
    cout<<vec.size()<<endl;
    for (auto p:vec)
    {
        cout<<p.first.first<<' '<<p.first.second<<' '<<p.second.first<<' '<<p.second.second<<endl;
    }
}