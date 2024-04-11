//julia are you here
//i am here
// we are doing C first.

#include <cstdio> //steven, we are using c++ sry, 
using namespace std; //j

typedef long long ll; //steven, we need <iostream> i think
#include <iostream> //does this have to be at the top

ll N; //steven, we find smallest k s.t. 3^k isn't factor of N, ans is ceil(N/3^k) i think

int main() //julia
{ //steven, cin >> N reads in N.
cin>>N;//julia
ll pow = 1; //steven
while (N % pow == 0) //julia just testing you
    pow *= 3; //steven, == 0 is what you want good test.
cout<<(N+pow-1)/pow; //julia damn how do i ceiling
return 0; //we're done here
}//julia mvp

//compilation error


// http://codeforces.com/contest/334/submission/4202463 uh oh
// ok you cout'd wrong.