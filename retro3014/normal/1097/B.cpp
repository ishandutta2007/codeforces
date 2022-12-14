#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>

using namespace std;

int N;
deque<int> dq;
int a;

using namespace std;

int main(){
    scanf("%d", &N);
    dq.push_back(0);
    for(int i=0 ;i<N; i++){
        scanf("%d", &a);
        int sz=dq.size();
        int now;
        while(sz--){
            now=dq.front(); dq.pop_front();
            dq.push_back((now+a)%360);
            dq.push_back((now-a+360)%360);
        }
    }
    for(int i=0; i<dq.size(); i++){
        if(dq[i]==0){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}