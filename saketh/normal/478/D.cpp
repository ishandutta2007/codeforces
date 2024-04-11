#include <iostream>
using namespace std;

int R, G, H;
int ways[2][200005];

int main(){
    cin >> R >> G;

    H = 1;
    while( (H+1)*(H+2)/2 <= (R+G) ) H++;

    ways[0][0] = 1;

    while(true){

        for(int h=1; h<=H; h++)
            for(int b=0; b<=200000; b++){
                ways[h%2][b] = ways[(h+1)%2][b];
                if(h <= b) ways[h%2][b] = (ways[h%2][b] + ways[(h+1)%2][b-h]) % 1000000007;
            }
    
        int need = H * (H+1) / 2;
        int fin = 0;

        while( (R>=0) && R+G >= need){
            fin = (fin + ways[H%2][R]) % 1000000007;
            R--;
        }

        if(fin) { cout << fin << endl; break; }
        else H--;
    }
    return 0;
}