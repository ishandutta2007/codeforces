#include <iostream>
#include <algorithm>

using namespace std;
#define MAX_N 100000
#define INF 2000000000

int N;
int arr[MAX_N+1];
int x=INF, y=INF;

int main(){
    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        arr[i]-=i;
        if(y>(arr[i]+(N-1))/N){
            y=(arr[i]+(N-1))/N;
            x=i;
        }
    }
    cout<<x+1;
    return 0;
}