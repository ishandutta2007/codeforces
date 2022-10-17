#include <iostream>
#include <algorithm>
using namespace std;

int N;
int flowers[200005];

int main(){
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> flowers[i];
    sort(flowers, flowers + N);

    int low = flowers[0];
    int high = flowers[N-1];

    if(low == high)
         cout << 0 << " " << ((long long)N) * (N-1) / 2 << endl;
    else{
        long long i = 0, j = N-1;
        while(flowers[i] == flowers[0]) i++;
        while(flowers[j] == flowers[N-1]) j--;
        cout << flowers[N-1] - flowers[0] << " " << i * (N-1-j) << endl;
    }

    return 0;
}