#include <iostream>
using namespace std;
int T(int a){
    if(a == 0){
        return 1;
    }
    return T(a-1)*2;
}
int abs(int a){
    if(a<=0){
        return (-1)*a;
    }
    return a;
}
long long C(int k,int n){
    if(k == n)
        return 1;
    if(k == 0)
        return 1;
    int cnt = 1;
    int cnt2 = 1;
    for(int i = 0; i < k;i++){
        cnt*=i+1;
        cnt2*=n-i;
    }
    return cnt2/cnt;
}
int main(){
    string a,b;
    cin >> a >> b;
    int cnt1 = 0;
    int cnt2 = 0;
    int QM = 0;
    for(int i = 0; i < a.length();i++){
        if(a[i] == '+')
            cnt1++;
        else
            cnt1--;
    }
    for(int i = 0; i < b.length();i++){
        if(b[i] == '+')
            cnt2++;
        else if(b[i] == '-')
            cnt2--;
        else
            QM++;
    }
    cout.precision(9);
    if(abs(cnt1-cnt2)>QM){
        cout << 0 << endl;
        return 0;
    }
    if(abs(cnt1-cnt2)%2 != QM%2){
        cout << 0 << endl;
        return 0;
    }
    cout << (float)C(abs(cnt1-cnt2)+(QM-abs(cnt1-cnt2))/2,QM)/T(QM) << endl;
    return 0;
}