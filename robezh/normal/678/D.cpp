#include<cstdio>
#include<iostream>
using namespace std;

typedef long long ll;

const int mod = 1000000007;

struct Mat {
    ll mat[2][2];
    
    Mat(int i = 1) {
        mat[0][0] = mat[1][1] = 1;
        mat[1][0] = mat[0][1] = 0;
    }



};

Mat operator * (Mat a, Mat b) {
    Mat res;
    for(int i = 0; i < 2; i++) for(int j = 0; j < 2; j++) res.mat[i][j] = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            ll sum = 0;
            for(int k = 0; k < 2; k++) {
                res.mat[i][j] += (a.mat[i][k] * b.mat[k][j]) % mod;
            }
        }
    }
    return res;
}


Mat operator ^ (Mat a, ll pow) {
    if(pow == 0) return Mat(1);
    if(pow % 2 == 1) return (a * (a ^ (pow -1)));
    else {
        Mat t = a ^ (pow/2);
        return (t * t);
    }
}


int main() {
    ll a,b,n,x;
    cin >> a >> b >> n >> x;
    Mat base = Mat(1);
    base.mat[0][0] = a;
    base.mat[0][1] = b;
//    Mat exp1 = base;
//    for(int i = 1; i < n; i++) exp1 =  exp1 * base;
    Mat exp = base ^ n;
    cout << (exp.mat[0][0] * x + exp.mat[0][1]) % mod << endl;
//    cout << (exp1.mat[0][0] * x + exp1.mat[0][1]) % mod << endl;
}