#include<stdio.h>
#include<vector>
using namespace std;

int N, E, unseen1, unseen2;
vector<int> e1[2005];
vector<int> e2[2005];
bool seen1[2005];
bool seen2[2005];

void dfs1(int loc){
    if(seen1[loc]) return;
    unseen1--;
    seen1[loc] = true;
    for(int i=0; i<e1[loc].size(); i++)
        dfs1(e1[loc][i]);
}

void dfs2(int loc){
    if(seen2[loc]) return;
    unseen2--;
    seen2[loc] = true;
    for(int i=0; i<e2[loc].size(); i++)
        dfs2(e2[loc][i]);
}

int main(){
    scanf("%d", &N);
    unseen1 = N;
    unseen2 = N;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++){
            scanf("%d", &E);
//            if(i==j) E--;
            if(E > 0){
                e1[i].push_back(j);
                e2[j].push_back(i);
            }
        }    
    dfs1(0);
    dfs2(0);
    if(unseen1 || unseen2) printf("NO\n");
    else printf("YES\n");
}