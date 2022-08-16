#include <iostream>
#include <cstdio>
using namespace std;

#define s(T) scanf("%lld", &T)

long long H, W;
int main()
{
	s(H);
	s(W);
	
	long long bestHeight = 0, bestArea = 0;
	long long consHeight, consArea;
	
	for(long long w = 1; w <= W; w = w<<1)
	{
		if(5 * H < (w<<2) )
		{
			consArea = 0ll;
			consHeight = 0ll;
		}
		else if ((H<<2) > (w*5) )
		{
			consArea = w * ((w*5)>>2);
			consHeight = ((w*5)>>2); 
		}
		else 
		{
			consArea = w * H;
			consHeight = H;
		}
		
		if(consArea > bestArea)
		{
			bestArea = consArea;
			bestHeight = consHeight;
		}
		else if(consArea == bestArea)
		{
			bestHeight = max(bestHeight, consHeight);
		}
	}
	
	for(long long h = 1; h <= H; h = h<<1)
	{
		if(5 * W < (h<<2) )
		{
			consArea = 0ll;
			consHeight= 0ll;
		}
		else if( (W<<2) > (h*5) )
		{
			consArea = h * ((h*5)>>2);
			consHeight = h;
		}
		else 
		{
			consArea = h * W;
			consHeight = h;
		}
		
		if(consArea > bestArea)
		{
			bestArea = consArea;
			bestHeight = consHeight;
		}
		else if(consArea == bestArea)
		{
			bestHeight = max(bestHeight, consHeight);
		}
	}
	
	cout << bestHeight << " " << (bestArea / bestHeight) << endl;
}