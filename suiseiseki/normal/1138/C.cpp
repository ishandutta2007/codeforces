#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
int h[1005][1005];
vector<int> r[1005],c[1005];
int main(){
	scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    		scanf("%d",&h[i][j]);
		}
	}
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        	r[i].push_back(h[i][j]);
		}
        sort(r[i].begin(),r[i].end());
        r[i].erase(unique(r[i].begin(),r[i].end()),r[i].end());
    }
    for(int j=1;j<=m;j++){
        for(int i=1;i<=n;i++){
        	c[j].push_back(h[i][j]);
		}
        sort(c[j].begin(),c[j].end());
        c[j].erase(unique(c[j].begin(),c[j].end()),c[j].end());
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int tp1=lower_bound(r[i].begin(),r[i].end(),h[i][j])-r[i].begin();
            int tp2=lower_bound(c[j].begin(),c[j].end(),h[i][j])-c[j].begin();
            int tp3=r[i].end()-lower_bound(r[i].begin(),r[i].end(),h[i][j]);
            int tp4=c[j].end()-lower_bound(c[j].begin(),c[j].end(),h[i][j]);
            printf("%d ",max(tp1,tp2)+max(tp3,tp4));
        }
        puts("");
    }
    return 0;
}