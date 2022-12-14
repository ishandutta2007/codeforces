#include <iostream>
using namespace std;
long long KS[2014*2];
int t[2014];
int c[2014];
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++){
        cin >> t[i] >> c[i];
        t[i]++;     
    }
    KS[0] = 0;
    for(int i = 1; i <= n+2000;i++)
        KS[i] = (long long)1000*1000*1000*2000+1;
    for(int i = 0; i < n;i++){
        for(int j = n+2000; j >= 0;j--){
            if(j-t[i] >= 0 && KS[j-t[i]] != (long long)2000*1000*1000*1000+1){
                KS[j] = min(KS[j-t[i]]+c[i],KS[j]);
            }
        }
    }
    long long counter = (long long)2000*1000*1000*1000+1;
    for(int i = n; i <= n+2000;i++){
        counter = min(KS[i],counter);
    }
    cout << counter << endl;
    return 0;
}