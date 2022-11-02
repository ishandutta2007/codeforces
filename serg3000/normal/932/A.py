s = input()
n = len(s)
s2 = s
if n % 2 == 0:
    for i in range(n - 1, -1, -1):
        s2 += s[i]
else:
    for i in range(n - 2, -1, -1):
        s2 += s[i]    
print(s2)