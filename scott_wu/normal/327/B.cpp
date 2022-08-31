#include <iostream> //scott
#include<cstdio>

using namespace std; //scott

int main(){ //demi
	int N; cin >> N; //scott
   int s = 0;
   for (int i = 3; s < N; i+=2) //scott
   {
     bool check = true; //scott
     for (int j = 3; j * j <= i; j+=2)
		if (i % j == 0) {check = false; break; }//scott
     s += check;
	if (check) cout << i << " ";
   }
  
	return 0;
}