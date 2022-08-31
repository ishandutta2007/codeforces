#include <iostream> //scott so we can just do 1, N+2, 2N+3,.... and then 2,N+3,2N+4,etc

using namespace std;

int main() //scott
{ //demi
    int N; cin >> N; //scott
    for (int i = 1; i <= N; i++)
        for (int j = 0; j < N; j++) //scott something like j * N + 1 + (i + j) % N
        {
          cout << j * N + 1 + (i + j) % N << " "; //scott
          if (j == N-1) cout<<endl;
         } //scott
return 0;
}