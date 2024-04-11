a, b, s = map(int ,input().split())
a = abs(a)
b = abs(b)
x = a + b
if x % 2 == s % 2 and x <= s:
    print("Yes")
else:
    print("No")