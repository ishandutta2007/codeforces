a = input().split(":")
b = input().split(":")
m = int(a[0]) * 60 + int(a[1]) + int(b[0]) * 60 + int(b[1])
m //= 2
ans = str(m % 60)
if (len(ans) == 1):
	ans = "0" + ans
ans = ":" + ans
ans = str(m // 60) + ans
if (len(ans) == 4):
	ans = "0" + ans
print(ans)