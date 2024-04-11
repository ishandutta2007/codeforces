#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define all(v) (v).begin(), (v).end()
#define MAX_N 200000
#define INF 2000000000

typedef long long ll;

int N;
int arr[MAX_N+1];
ll sum, s;

vector<ll> v;

int main(){
    cin>>N;v.push_back(0);v.push_back(0);
    for(int i=0; i<N; i++){
        scanf("%d", &arr[i]);
        sum+=(ll)arr[i];
    }
    for(int i=0; i<N; i++){
        s+=(ll)arr[i];
        v.push_back(min(s, sum-s));
        if(s==sum-s){
            cout<<s;
            return 0;
        }
    }
    sort(all(v));
    while(1){
        if(v.back()==v[v.size()-2]){
            cout<<v.back();
            return 0;
        }
        v.pop_back();
    }
    return 0;
}