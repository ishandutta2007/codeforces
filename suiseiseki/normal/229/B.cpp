#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
void read(int &a){
	a=0;
    char c=getchar();
    while(c<'0'||c>'9'){
    	c=getchar();
	}
    while(c>='0'&&c<='9'){
    	a=(a<<1)+(a<<3)+c-'0';
        c=getchar();
    }
}
vector<int> K[100005];
vector<pair<int,int> > edge[100005];
int d[100005];
struct node{
    int w;
    int val;
    node(int _w=0,int _val=0){
    	w=_w;
    	val=_val;
	}
	friend bool operator >(node a,node b){
		return a.val>b.val;
	}
};
node make_node(int w,int val){
	node now(w,val);
	return now;
}
priority_queue<node,vector<node>,greater<node> > q;
inline int search(vector<int> k,int val){
    int s=0,t=k.size()-1;
    while(s<=t){
        int mid=(s+t)>>1;
        if(k[mid]==val){
        	return mid;
		}
        else if(k[mid]<val){
        	s=mid+1;
		}
        else{
        	t=mid-1;
		}
    }
    return -1;
}
int n,m,a,b,c,k;
bool vis[100005];
int main(){
	read(n);
	read(m);
	memset(d,0x3f,sizeof(d));
	d[1]=0;
    while(m--){
    	read(a),read(b),read(c);
        edge[a].push_back(make_pair(b,c));
        edge[b].push_back(make_pair(a,c));
    }
    for(int i=1;i<=n;i++){
    	read(k);
        while(k--){
            read(a);
            K[i].push_back(a);
        }
    }
    q.push(make_node(1,0));
    int x,pp,r,p,nxt,val;
    while(!q.empty()){
    	x=q.top().w;
        q.pop();
        if(vis[x]==1){
        	continue;
		}
        vis[x]=1;
        pp=d[x];
        if(!K[x].empty()){
            r=search(K[x],pp);
            if(r!=-1){
                pp++;
                r++;
                while(r<(int)K[x].size()&&pp==K[x][r]){
                    r++;
					pp++;
                }
            }
        }
        for(unsigned i=0;i<edge[x].size();i++){
            nxt=edge[x][i].first;
            val=edge[x][i].second;
            p=pp+val;
            if(p<d[nxt]){
                d[nxt]=p;
                q.push(node(nxt,p));
            }
        }
    }
    if(d[n]==0x3f3f3f3f){
    	puts("-1");
	}
    else{
    	printf("%d\n",d[n]);
	}
	return 0;
}
//
//