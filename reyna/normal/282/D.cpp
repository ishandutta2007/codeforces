//In the name of God
#include <iostream>
using namespace std;
const int Maxn = 320;
int all[Maxn][Maxn];
int once[Maxn][Maxn];
int win[Maxn][Maxn][Maxn];
int arr[3];
bool Win(int i,int j,int k,int n){
    if(n < 3)
        k = 0;
    if(i < 0 || j < 0 || k < 0)
        return 1;
    if(win[i][j][k])
        return 2-win[i][j][k];
    Win(i-1,j,k,n);
    Win(i,j-1,k,n);
    if(n == 3)
        Win(i,j,k-1,n);
    Win(i-1,j-1,k-1,n);
    int one = min(i,min(j,k));
    if(n != 3)
        one = min(i,j);
    int num = 0;
    if(j == one)
        num = 1;
    if(n == 3)
        if(k == one)
            num = 2;
    int two = 0;
    int three = 0;
    if(num == 1){
        two = i;
        three = k;
    }
    if(num == 2){
        two = i;
        three = j;
    }
    if(!num){
        two = j;
        three = k;
    }
    if(n == 2){
        two = i;
        three = j;
    }
    if((!all[two-one][three-one] || !all[three-one][two-one]) && (n != 3 || !once[one][two] || !once[two][one]) && (n != 3 || !once[one][three] || !once[three][one]) && (n != 3 || !once[two][three] || !once[three][two]) && (n != 2 || !once[two][0] || !once[0][two]) && (n != 2 || !once[three][0] || !once[0][three])){
        all[two-one][three-one] = 1;
        all[three-one][two-one] = 1;
        if(n == 3){
            once[one][two] = 1;
            once[two][one] = 1;
            once[three][one] = 1;
            once[one][three] = 1;
            once[two][three] = 1;
            once[three][two] = 1;
        }
        if(n == 2){
            once[two][0] = 1;
            once[0][two] = 1;
            once[three][0] = 1;
            once[0][three] = 1;
        }
//      }
        win[i][j][k] = 2;
        return 0;
    }
    win[i][j][k] = 1;
    return 1;
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n;i++)
        cin >> arr[i];
    if(n == 1 && !arr[0]){
        cout << "BitAryo" << endl;
        return 0;
    }else if(n == 1){
        cout << "BitLGM" << endl;
        return 0;
    }
    win[0][0][0] = 2;
    once[0][0] = 1;
    all[0][0] = 1;
    if(Win(arr[0],arr[1],arr[2],n))
        cout << "BitLGM" << endl;
    else
        cout << "BitAryo" << endl;
    return 0;
}