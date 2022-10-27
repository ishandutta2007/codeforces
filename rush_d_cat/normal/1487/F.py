n = int(input())
res={}
def cal(x):
	if x==0: return 0
	if x in res.keys(): return res[x]

	l = len(str(x)); n1 = (10**l)//9; ans = 10**9
	#print(x,l,n1)

	if x < n1: n1=n1//10; l=l-1
	ans = min(cal(x % n1) + (x//n1) * l, ans)
	tmp = cal((n1 * 10 + 1 - x) % n1) + (l + 1) + ((n1 * 10 + 1 - x) // n1) * l
	if tmp < ans: ans = tmp
	res[x] = ans
	return ans


print(cal(n))