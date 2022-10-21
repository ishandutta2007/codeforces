#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;



struct point {
    int a, b;
    int time;
    point() {
        a = 0;
        b = 0;
        time = 0;
    }
    point(int _a, int _b, int _time) {
        a = _a;
        b = _b;
        time = _time;
    }
    bool operator<(const point& p) const {
        return time < p.time;
    }
    bool operator>(const point& p) const {
        return time > p.time;
    }
};



const int INF = 1000000000;

bool visited[1005][1005];
int n,m,k;
char myth[1005][1005];
int a1,b1,a2,b2;
int mindist[1005][1005];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
priority_queue<point, vector<point>, greater<point> > pque;
//queue<point> pque;

bool inbound(int a1, int b1) {
    return a1 >= 0 && a1 < n && b1 >= 0 && b1 < m;
}

void setdijkstra() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            mindist[i][j] = INF;
            visited[i][j] = false;
        }
    }
    
    mindist[a1][b1] = 0;
    visited[a1][b1] = true;
    pque.push(point(a1,b1,0));
    while(pque.size()) {
        int dis = pque.top().time;
        int a = pque.top().a;
        int b = pque.top().b;
        pque.pop();
        //printf("%d\n ",pque.size());
        
        //if(dis > mindist[a][b]) continue;
        for(int i = 0; i < 4; i++) {
        	//printf("a = %d b = %d: i = %d\n",a,b,i);
            for(int j = 1; j <= k; j++) {
                int ato = a + j * dx[i], bto = b + j * dy[i];
                if(!inbound(ato, bto)) {
                	break;
				}
				
                if(myth[ato][bto] == '#'){
                	break;
				} 
				
                if(dis + 1 > mindist[ato][bto]){
					break;
				} 
				//if(ato == 0 && bto == 2) printf("%d",visited[ato][ato]);
				//printf("visited[%d][%d] = %d\n", i,j,visited[i][j]);
				if(visited[ato][bto]) continue; 
                
				visited[ato][bto] = true;
                mindist[ato][bto] = mindist[a][b] + 1;
                    //printf("mindst[%d][%d] is assigned to %d\n", ato, bto, dis+1);
                pque.push(point(ato,bto,dis+1));
                //printf("point %d %d %d is pushed\n", ato, bto, dis+1);
            }
        }
    }
}


int main() {
    scanf("%d%d%d", &n,&m,&k);
    for(int i = 0; i < n; i++) {
    	getchar();
        for(int j = 0 ; j < m; j++) {
            scanf("%c", &myth[i][j]);
        }
    }
//    for(int i = 0; i < n; i++) {
//        for(int j = 0 ; j < m; j++) {
//            printf("%c", myth[i][j]);
//        }
//    }
    scanf("%d%d%d%d", &a1,&b1,&a2,&b2);
    a1--;b1--;a2--;b2--;
    setdijkstra();
//    for(int i = 0; i < n; i++) {
//        for(int j = 0 ; j < m; j++) {
//            printf("%d ", mindist[i][j]);
//        }
//        printf("\n");
//    }
    if(mindist[a2][b2] == INF) printf("-1");
    else printf("%d", mindist[a2][b2]);
    

}