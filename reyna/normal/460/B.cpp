#include <iostream>
using namespace std;
long long tavan[82];
bool ans1[90];
long long ans[90];
int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    for(int i = 0; i < 82;i++){
        long long counter = 1;
        for(int j = 0; j < a; j++){
            counter*=i;
        }
        tavan[i] = counter;
    }
    long long d = 0;
    for(int i = 0;i < 82;i++){
        long long x;
        x = b*tavan[i]+c;
        long long counter = 0;
        while(x!=0){
            counter+=x%10;
            x/=10;
        }
        if(counter == i && (b*tavan[i]+c)<1000000000 && (b*tavan[i]+c)>0){
            d++;
            ans[i] = b*tavan[i]+c;
            ans1[i] = true;
        }
    }
    cout << d << endl;
    for(int i = 0; i < 90;i++){
        if(ans1[i] == true){
            cout << ans[i] << " ";
        }
    }
}