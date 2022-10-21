#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

const int INF = 1000000000;

struct item {
    int time;
    int dura;
    int val;
    int index;
} it[105];

bool cmp(item a, item b){
	return a.dura < b.dura;
}

int dp[105][2050];
bool used[105][2050];
int n;
int tmpa,tmpb,tmpc;
int maxd;
int cnt;
vector<int> res;

int main() {
    int maxd = 0;
    for(int i = 0; i < 105; i++) {
        fill(dp[i], dp[i] + 2050, -INF);
        fill(used[i], used[i] + 2050, false);
    }
    dp[0][0] = 0;
    scanf("%d",&n);
    for(int i = 0; i < n; i++) {
        scanf("%d%d%d",&tmpa,&tmpb,&tmpc);
        it[i].time = tmpa;
        it[i].dura = tmpb;
        it[i].val = tmpc;
        it[i].index = i;
        maxd = max(maxd, tmpb);
    }
    sort(it, it+n, cmp);
//    printf("\n");
//    for(int i = 0; i < n; i++) {
//        printf("%d %d %d\n", it[i].time,it[i].dura,it[i].val);
//    }
    //int res = 0;
    dp[0][0] = 0;
    if(it[0].time < it[0].dura){
    	dp[0][it[0].time] = it[0].val;
    	used[0][it[0].time] = true;
	} 
    for(int i = 1; i < n; i++) {
    	for(int j = 0; j <= it[i].dura - 1; j++){
    		dp[i][j] = dp[i-1][j];
		}
        for(int j = it[i].dura - 1; j >= it[i].time; j--) {
        	if(dp[i-1][j-it[i].time] != -INF && dp[i-1][j-it[i].time] + it[i].val > dp[i][j]){
        		dp[i][j] = dp[i-1][j-it[i].time] + it[i].val;
        		used[i][j] = true;
			}
        }
    }

    int maxres = 0;
    int maxtime = -1;
    for(int i = 0; i <= maxd; i++) {
        if(maxres <= dp[n-1][i]) {
            maxres = dp[n-1][i];
            maxtime = i;
        }
    }
    
    int pos = n-1;
    //printf("dp[5][1] = %d\n", dp[5][1]);
    while(pos >= 0) {
        //if(dp[pos][1] == 0) break;
        if(used[pos][maxtime]){
        	//printf("used[%d][%d] is true so it[%d].indexis pushed\n",pos,maxtime,it[pos]);
        	maxtime -= it[pos].time;
        	res.push_back(it[pos].index);
        	pos--;
		}
		else{
			pos--;
		}
//        printf("pos = %d\n",pos);
        
    }
    //printf("dp[1][5] = %d\n", );
    printf("%d\n",maxres);
    printf("%d\n",res.size());
    for(int i = res.size() - 1; i >= 0; i--) {
        printf("%d ",res[i] + 1);
    }
}