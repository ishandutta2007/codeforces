#include<iostream>
using namespace std;

int H;
char V;
int c[10];
bool good = true;

int main(){
    cin >> H;
    for(int x=0; x<4; x++)
        for(int y=0; y<4; y++){
            cin >> V;
            if(V>'9' || V<'1') continue;
            c[V-'1']++;
            if(c[V-'1'] > 2*H) good = false;
        }
    if(good) cout << "YES" << endl;
    else cout << "NO" << endl;
}