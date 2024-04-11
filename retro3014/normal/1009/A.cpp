#include <iostream>
#include <vector>
#include <deque>
#include <stdio.h>

using namespace std;

#define MAX_N 1000
int N, M;
deque<int> dq1;
deque<int> dq2;
int x;
int ans;

int main(){
    cin>>N>>M;
    for(int i=1; i<=N; i++){
        scanf("%d", &x);
        dq1.push_back(x);
    }
    for(int i=1; i<=M; i++){
        scanf("%d", &x);
        dq2.push_back(x);
    }
    while(!dq1.empty() && !dq2.empty()){
        if(dq1.front()<=dq2.front()){
            ans++;
            dq1.pop_front();
            dq2.pop_front();
        }
        else {
            dq1.pop_front();
        }
    }
    cout<<ans;
    
    return 0;
}