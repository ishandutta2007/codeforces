#include <bits/stdc++.h>



using namespace std;



int main() {

	int stx, sty, edx, edy;

	cin>>stx>>sty>>edx>>edy;

	

	if(stx==edx || sty==edy) cout<<1<<' ';

	else cout<<2<<' ';

	

	if(((stx+sty)%2) != ((edx+edy)%2)) cout<<0<<' ';

	else if(stx+sty==edx+edy || stx-sty==edx-edy) cout<<1<<' ';

	else cout<<2<<' ';

	

	cout<<max(abs(stx-edx), abs(sty-edy))<<endl;



	return 0;

}