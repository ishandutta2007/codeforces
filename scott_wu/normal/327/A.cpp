#include <iostream> //scott
#include<cstdio>

using namespace std; //scott

int main()
{ //scott
  int n,a[200];
	cin >> n;
  for (int i = 1; i <= n; i++)
 cin >> a[i-1];
  int best = 0;
  for (int i = 0; i < n; i ++)
	for (int j = i; j < n; j++) //scott
    {int s = 0;
		for (int k = i; k <= j; k++) a[k] = 1 - a[k]; //scott
       for (int k = 0; k < n; k++) s += a[k];
		for (int k = i; k <= j; k++) a[k] = 1 - a[k]; //scott  
    if (s> best) best = s;
  }//scott
 cout<< best << endl;
return 0;//scott
}