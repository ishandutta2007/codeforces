#include <iostream>

#define maxn 1000010

using namespace std;

int n;
const int maxnum = 1000500;
int matrix[maxn];

int less1(int a, int b){
    if (a <= b) return a;
    else return b;
}

int main(){
    cin >> n;
    matrix[0] = 0;
    for(int i = 1; i < 4; i++) matrix[i] = maxnum;
    matrix[4] = 1;
    for(int i = 5; i < 7; i++) matrix[i] = maxnum;
    matrix[7] = 1;
    for(int i = 8; i<= n; i++){
        matrix[i] = less1(matrix[i - 4] + 1, matrix[i - 7] + 1);
        matrix[i] = less1(matrix[i], maxnum);
    }
    if (matrix[n] == maxnum) cout << "-1" << endl;
    else
    {
        for(int i = n; i > 0;){
            int a1, b1;
            if (i >= 4) a1 = matrix[i - 4];
            else a1 = maxnum;
            if (i >= 7) b1 = matrix[i - 7];
            else b1 = maxnum;
            if (a1 <= b1){
                cout << "4";
                i -= 4;
            }
            else
            {
                cout << "7";
                i -= 7;
            }
        }
        cout << endl;
    }
    return 0;
}