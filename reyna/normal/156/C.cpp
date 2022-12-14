#include <iostream>
#include <string>
using namespace std;
long long ans[10000];
long long c[2601][2601];
int main(){
    long long D = 1000000007;
    for(int i = 0; i <= 2600;i++){
        for(int j = 0; j <= i; j++){
            if(i == j){
                c[i][j] = 1;
            }else if(j == 0){
                c[i][j] = 1;
            }else{
                c[i][j] = (c[i-1][j-1] + c[i-1][j])%D;
            }
        }
    }
    int t;
    cin >> t;
    for(int i = 0; i < t;i++){
        string a;
        cin >> a;
        long long counter = 0;
        for(long long j = 0;j < a.length(); j++){
            counter += int(a[j])-96;
        }
        long long k = 0;
        long long j = counter;
        while(j >= int(a.length())){
            if(k == int(a.length())+1){
                break;
            }
            if(k % 2 == 0){
                ans[i] = (ans[i] + ((c[j-1][a.length()-1])*c[a.length()][k]));
            }else{
                ans[i] = (ans[i] - ((c[j-1][a.length()-1])*c[a.length()][k]));
            }
            k++;
            j -= 26;
        }
        ans[i]%=D;
    }
    for(int i = 0; i < t;i++){
        if(((ans[i]-1)%1000000007) < 0){
            cout << D-(((ans[i]-1)%1000000007)*(-1)) << endl;
        }else{
            cout << (ans[i]-1)%1000000007 << endl;
        }
    }
    return 0;
}