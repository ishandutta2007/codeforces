#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>


using namespace std;

long long toSq(long long a1){
    long long a = (long long)(sqrt(a1));
    //cout << a*a - a1 << endl;
    return min(abs(a*a - a1), a*a + a * 2 + 1 - a1);
}

long long toUnSq(long long a1){
    long long res = 0;
    if(sqrt(a1) == (long long)(sqrt(a1))){
        if(a1 >= 1) res = 1;
        else res = 2;
    }
    return res;
}

int main(){
    int n;
    cin >> n;

    vector <long long> a(n);
    for (int i = 0; i < n; i++)cin >> a[i];

    //vector <int> sqs = Sqs();

    vector<long long> a1(n), a2(n);
    for(int i = 0; i < n; i++){
        a1[i] = toSq(a[i]);
        a2[i] = toUnSq(a[i]);
        //cout << a1[i] << ' ' << a2[i] << endl;
    }

    int n1 = 0;
    for(int i = 0; i < n; i++)if(a1[i] == 0)n1++;


    long long cnt = 0;
    if(n1 > n / 2){

        sort(a2.begin(), a2.end());
        for(int i = n - n1; i < n / 2; i++){cnt += a2[i]; }
    }
    else if(n1 < n / 2){

        sort(a1.begin(), a1.end());
        for(int i = n1; i < n / 2; i++)cnt += a1[i];
    }
    cout << cnt;
}