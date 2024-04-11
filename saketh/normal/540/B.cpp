#include <iostream>
using namespace std;

int N, K, P, X, Y;
int marks[1000];

int main(){
    cin >> N >> K >> P >> X >> Y;

    int sum = 0, blw = 0;
    for(int i=0; i<K; i++){
        cin >> marks[i];
        sum += marks[i];
        blw += int(marks[i] < Y);
    }

    for(int i=K; i<N; i++){
        if(blw < (N/2)){
            marks[i] = 1;
            sum += 1;
            blw++;
        }
        else{
            marks[i] = Y;
            sum += Y;
        }
    }

    if(blw > N/2 || sum > X) cout << -1 << endl;
    else{
        for(int i=K; i<N; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
}