#include<iostream>
using namespace std;

int main(){
    int N, K;
    int v[1005];
    
    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> v[i];
    
    int B = -1, C = 1000;
    for(int f=1; f<=1000; f++){
        int mc = 0;
        for(int i=0; i<N; i++)
            if(v[i]!=f+i*K)
                mc++;
        if(mc < C){
            C = mc;
            B = f;
        }
    }
    
    cout << C << endl;    
    for(int i=0; i<N; i++)
        if(v[i] < B+i*K)
            cout << "+ " << i+1 << " " << B+i*K-v[i] << endl;
        else if(v[i] > B+i*K)
            cout << "- " << i+1 << " " << v[i]-(B+i*K) << endl;
    return 0;
}