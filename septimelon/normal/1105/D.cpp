#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,k;
string vvod[2000];
char a[2000][2000];
int p[10];
int ost;
int ans[10];
vector<pair<int,int>> ver[10];
vector<pair<int,int>> ver1[10];
pair<int,int> deq[1500000];
int dist[1500000];
int j_0;
int j_1;
void dfs(int k1,int i){
    j_0=0;
    j_1=1;
    ans[k1]--;
    ost--;
    deq[0]=ver[k1][i];
    while(j_0<j_1){
        int x=deq[j_0].first;
        int y=deq[j_0].second;
        char xxx='1'+k1;
        ans[k1]++;
        ost++;
        a[x][y]=xxx;
        if(dist[j_0]<p[k1]){
            if(y<m&&a[x][y+1]=='.'){
                deq[j_1]=make_pair(x,y+1);
                a[x][y+1]=xxx;
                dist[j_1]=dist[j_0]+1;
                j_1++;
            }
            if(y>0&&a[x][y-1]=='.'){
                deq[j_1]=make_pair(x,y-1);
                a[x][y-1]=xxx;
                dist[j_1]=dist[j_0]+1;
                j_1++;
            }
            if(x<n&&a[x+1][y]=='.'){
                deq[j_1]=make_pair(x+1,y);
                a[x+1][y]=xxx;
                dist[j_1]=dist[j_0]+1;
                j_1++;
            }
            if(x>0&&a[x-1][y]=='.'){
                deq[j_1]=make_pair(x-1,y);
                a[x-1][y]=xxx;
                dist[j_1]=dist[j_0]+1;
                j_1++;
            }
        }
        else{
            ver1[k1].push_back(deq[j_0]);
        }
        j_0++;
    }
}
int main() {
	//ios_base::sync_with_stdio(false);
	cin>>n>>m>>k;
	for(int i=0;i<k;i++)cin>>p[i];
	for(int i=0;i<n;i++)cin>>vvod[i];
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++) a[i][j]=vvod[i][j];
	}
//    for(int i=0;i<n;i++){
//	        for(int j=0;j<m;j++) a[i][j]='.';
//	}
//	a[0][0]='2';
//	a[999][999]='1';
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++){
	        if(a[i][j]=='.') ost++;
	        if(a[i][j]>='1'&&a[i][j]<='9'){
	            int x=a[i][j]-'1';
	            ans[x]++;
	                ver[x].push_back(make_pair(i,j));

	        }
	    }
	}

	while(ost>0){
	    ost=0;
	    for(int i=0;i<k;i++){
	        for(int j=0;j<ver[i].size();j++){
	            dfs(i,j);
	        }
	    }
	    for(int i=0;i<k;i++){
	        ver[i].resize(ver1[i].size());
	        for(int j=0;j<ver1[i].size();j++){
	            ver[i][j]=ver1[i][j];
	        }
	        ver1[i].resize(0);
	    }
	}
   // for(int i=0;i<n;i++){
   //     for(int j=0;j<m;j++){
   //         cout<<a[i][j];
  //      }
  //      cout<<endl;
  //  }
	for(int i=0;i<k;i++){
	    cout<<ans[i]<<" ";
	}
	return 0;
}