#include<iostream>
#include<algorithm>
using namespace std;

int N;
int m[300005];
pair<int, int> p[300005];
int r[300005];

int main(){
    cin >> N;
    for(int n=0; n<N; n++){
        cin >> m[n];
        p[n] = make_pair(m[n], n);
    }
    
    sort(p, p+N);
    int LR = 0;
    
    for(int n=0; n<N; n++){
        if(LR < p[n].first){
            LR = p[n].first;
            r[p[n].second] = LR;
        }
        else{
            LR++;
            r[p[n].second] = LR;
        }
    }
    
    for(int n=0; n<N; n++){
        cout << r[n];
        if(n < N-1) cout << " ";
    }
    cout << endl;
    
    return 0;
}