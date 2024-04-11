#include <map>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
# define ll long long
# define Inf 0x3f3f3f3f
vector<pair<int,int> >vis;
map<pair<int,int>,bool>ju;
struct node{
    int x;
    int y;
} q[20];
bool cmp(node t1,node t2){
    if(t1.x==t2.x){
    	return t1.y<t2.y;
	}
    return t1.x<t2.x;
}
int main(){
    int x1,y1,x2,y2,x3,y3;
    scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3);
    int miny=Inf,maxy=0;
    miny=min(miny,y1);
    miny=min(miny,y2);
    miny=min(miny,y3);
    maxy=max(maxy,y1);
    maxy=max(maxy,y2);
    maxy=max(maxy,y3);
    q[1].x=x1;
    q[1].y=y1;
    q[2].x=x2;
    q[2].y=y2;
    q[3].x=x3;
    q[3].y=y3;
    sort(q+1,q+4,cmp);
    for(int i=miny;i<=maxy;i++){
        if(ju[make_pair(q[2].x,i)]==0){
        	vis.push_back(make_pair(q[2].x,i));
		}
        ju[make_pair(q[2].x,i)]=1;
    }
    for(int i=q[1].x;i<=q[2].x;i++){
        if(ju[make_pair(i,q[1].y)]==0){
        	vis.push_back(make_pair(i,q[1].y));
		}
        ju[make_pair(i,q[1].y)]=1;
    }
    for(int i=q[2].x;i<=q[3].x;i++){
        if(ju[make_pair(i,q[3].y)]==0){
        	vis.push_back(make_pair(i,q[3].y));
		}
        ju[make_pair(i,q[3].y)]=1;
    }
    printf("%d\n",(int)vis.size());
    for(int i=0;i<(int)vis.size();i++){
    	printf("%d %d\n",vis[i].first,vis[i].second);
	}
    return 0;
}