#include<iostream>          // Input/Output library
using namespace std;

int N, G, a, b, c, d;       // Make the variables we want to use

int main(){
	/* 	First we read in all the group sizes, counting
		the number of 1's, 2's, 3's, and 4's.			*/
	cin >> N;
	for(int i=0; i<N; i++){
		cin >> G;
		if(G == 1) a++;
		else if(G==2) b++;
		else if(G==3) c++;
		else if(G==4) d++;
	}

	int ans = 0;			// Now, we will compute the answer
	
	ans += d;				// All the groups of size 4 take up a whole taxi

	ans += c;				// Groups of 3 also need separate taxis
	a = max(a-c, 0);		// But we can squeeze in available 1's

	ans += b/2;				// Every two groups of 2 need a taxi together
	if(b%2 == 1){			// If there is an unpaired one
		ans++;				// We need one extra taxi for it
		a = max(a-2, 0);	// And we can squeeze in up to two 1's
	}

	ans += (a+3)/4;			// Finally, the 1's: divide by 4, but round up

	cout << ans << endl;	// Print the answer
	return 0;               // Exit the program
}