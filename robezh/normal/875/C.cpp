#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
using namespace std;

typedef pair<int, int> P;
int n,m;
int cnt;
int u[100050];
int len[100050];
vector<int> words[100050];
vector<int> edge[100050];
bool upcase[100050];
bool fst[100050];
int num;
vector<int> res;
bool good;

int find(int k){
	if(u[k] != k){
		u[k] = find(u[k]);
	}
	return u[k];
}

void unite(int a, int b){
	u[find(a)] = find(b);
}

void updateFirst(int frst, int scd){
	if(!(find(frst) == find(scd))){
		unite(frst,scd);
		fst[scd] = false;
	}
}

void dfs(int i) {
	cnt ++;
    if(!good) return;
    //printf("%d ",i);
    for(int j = 0; j < edge[i].size(); j++) {
    	if(edge[i][j] < i && !upcase[i]){
		    if(upcase[edge[i][j]]){
            	upcase[edge[i][j]] = false;
            	//printf("upcase[%d] = false\n",edge[i][j]);
            	res.push_back(edge[i][j]);
			}
    		//printf("upcase[%d] = false\n",edge[i][j]);
		}
        else if(edge[i][j] > i) {

            if(!upcase[i]) {
                good = false;
                return;
            }

            if(upcase[edge[i][j]]){
            	upcase[edge[i][j]] = false;
            	//printf("upcase[%d] = false\n",edge[i][j]);
            	res.push_back(edge[i][j]);
			}
//            printf("edge[i][j]: %d = false\n", edge[i][j]);
//            system("pause");
            
        }
        dfs(edge[i][j]);
    }
}

P getConnect(int i) {
    int leng = min(len[i], len[i-1]);
    for(int j = 0; j < leng; j++) {
        if(words[i][j] != words[i-1][j]) {
            return P(words[i][j],words[i-1][j]);
        }
    }
    if(len[i] >= len[i-1]) return P(m+1, m+1);
    else return P(m+2,m+2);
}

int main() {
	cnt = 0;
    good = true;
    scanf("%d%d",&n,&m);
    fill(upcase + 1, upcase + m + 1, true);
    fill(fst + 1, fst + m + 1, true);
    for(int i = 1; i <= m; i++) u[i] = i;
    for(int i = 0; i < n; i++) {
        scanf("%d",&len[i]);
        for(int j = 0; j < len[i]; j++) {
            scanf("%d",&num);
            words[i].push_back(num);
        }
    }
    for(int i = n-1; i > 0; i--) {
        P p = getConnect(i);
        if(p.first == m+1) {
            continue;
        }
        if(p.first == m+2) {
            good = false;
            break;
        }
        updateFirst(p.first,p.second);
        edge[p.first].push_back(p.second);
    }
//    for(int i = 1; i <= m; i++) {
//        printf("i = %d: ", i);
//            for(int j = 0; j < edge[i].size(); j++)
//                printf("%d ", edge[i][j]);
//        printf("\n");
//    }
    if(good) {
        for(int i = 1; i <= m; i++) {
            if(fst[i]) {
                dfs(i);
                if(!good) break;
            }
        }
    }
	if(!good) printf("No");
	else{
		printf("Yes\n");
		printf("%d\n",res.size());
		for(int i = 0; i < res.size(); i++){
			printf("%d ", res[i]);
		}
	}
	//printf("\ncnt = %d", cnt); 
}