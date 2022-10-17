#include <iostream>
#include <algorithm>
using namespace std;

string inp;

int EAB, LAB;
int EBA, LBA;

bool no_lap(int x, int y){
    if(!x || !y) return false;
    return abs(x-y) >= 2;
}

int main(){

    cin >> inp;
    for(int i=1; i<inp.size(); i++){
        if(inp[i] == 'B' && inp[i-1] == 'A'){
            if(!EAB) EAB = i;
            LAB = i;
        }
        
        if(inp[i] == 'A' && inp[i-1] == 'B'){
            if(!EBA) EBA = i;
            LBA = i;
        }
    }

    bool res = no_lap(EAB, EBA) | 
               no_lap(EAB, LBA) | 
               no_lap(LAB, EBA) | 
               no_lap(LAB, LBA);
    cout << (res ? "YES" : "NO") << endl;
}