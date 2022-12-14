#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <deque>

using namespace std;
#define MAX_N 200000

struct S{
    int idx, data;
    bool operator <(const S &a)const{
        return data<a.data;
    }
};

int N, M, D;
int t;
vector<S> v;
vector<int> group[MAX_N+1];
deque<int> dq;
int idx=0;
int ans[MAX_N+1];


int main(){
    scanf("%d %d %d", &N, &M, &D);
    for(int i=1; i<=N; i++){
        scanf("%d", &t); v.push_back({i, t});
    }
    sort(v.begin(), v.end());
    for(int i=0; i<N; i++){
        if(dq.empty()){
            group[idx].push_back(v[i].data);
            dq.push_back(idx);
            ans[v[i].idx]=idx;
            idx++;
        }
        else if(v[i].data-group[dq.front()].back()<=D){
            group[idx].push_back(v[i].data);
            dq.push_back(idx);
            ans[v[i].idx]=idx;
            idx++;
        }
        else{
            group[dq.front()].push_back(v[i].data);
            ans[v[i].idx]=dq.front();
            dq.push_back(dq.front()); dq.pop_front();
        }
    }
    printf("%d\n", idx);
    for(int i=1; i<=N; i++){
        printf("%d ", ans[i]+1);
    }
    
    return 0;
}