#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s="";
char a[1001][1001];
char ret[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for (char x='0';x<='9';x++)s+=x;
    for (char x='a';x<='z';x++)s+=x;
    for (char x='A';x<='Z';x++)s+=x;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        int R=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cin >> a[i][j];
                if (a[i][j]=='R')R++;
            }
        }
        vector<int> need;
        for (int i=0;i<k;i++) {
            need.push_back(R/k + (i<(R%k)));
        }
        int x=0,y=0;
        int p=1;
        int cur = 0;
        for (int i=0;i<n*m;i++) {
            if (a[x][y]=='R')need[cur]--;
            ret[x][y]=s[cur];
            if (need[cur]==0 && cur+1<k)cur++;
            y+=p;
            if (y<0){
                y=0,p=-p,x++;
            }
            if (y>=m){
                y=m-1,p=-p,x++;
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                cout<<ret[i][j];
            }
            cout<<endl;
        }
    }
}