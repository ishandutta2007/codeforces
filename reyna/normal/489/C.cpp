#include <iostream>
using namespace std;
int big[123];
int small[123];
int main(){
    int len,sum;
    cin >> len >> sum;
    if(sum == 0 && len == 1){
        cout << 0 << " " << 0<< endl;
        return 0;
    }
    if(sum == 0){
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    if(len*9 < sum){
        cout << -1 << " " << -1 << endl;
        return 0;
    }
    int tmplen = len;
    int tmpsum = sum;
    small[len-1]++;
    tmpsum--;
    for(int i = 0; i < len;i++){
        if(tmpsum >= 9){
            small[i]+=9;
            tmpsum-=9;
        }else{
            small[i]+=tmpsum;
            tmpsum = 0;
            break;
        }
    }
    tmplen = len;
    tmpsum = sum;
    for(int i = len-1;i >= 0;i--){
        if(tmpsum>=9){
            big[i]+=9;
            tmpsum-=9;
        }else{
            big[i]+=tmpsum;
            tmpsum=0;
            break;
        }
    }
    for(int i = len-1; i >= 0;i--){
        cout << small[i];
    }
    cout << " ";
    for(int i = len-1; i>= 0;i--){
        cout << big[i];
    }
    cout << endl;
    return 0;
}