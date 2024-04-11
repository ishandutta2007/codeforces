#include <iostream> //scott AC ok now read in long long N, find smallest power of 3 that doesn't divide N, find ceiling of N / that
#include<cmath> //

using namespace std; //scott N / smallest power of 3 not dividing N

int main()//ok
{ long long N; cin >> N; //scott
  long long t= 1;
    while (N % t == 0) t *= 3; //scott
  cout<<N/t+1<<endl;
    return 0; //scott
}