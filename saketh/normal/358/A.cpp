#include<iostream>
using namespace std;

int N;
int v[1005];

int main(){
    cin >> N;
    for(int c=0; c<N; c++)
        cin >> v[c];
        
    bool self = false;
    for(int a=0; a<N-1 && true; a++){
        for(int b=a+1; b<N-1 && true; b++){
            int al = min(v[a], v[a+1]);
            int ar = max(v[a], v[a+1]);
            int bl = min(v[b], v[b+1]);
            int br = max(v[b], v[b+1]);
            
            if(bl >= ar) continue;
            if(br <= al) continue;
            if(bl>=al && br<=ar) continue;
            if(bl<=al && br>=ar) continue;
            self = true;
        }
    }
    
    cout << (self? "yes" : "no") << endl;
    return 0;
}