s = input()
n = len(s)
a = 0
for i in range(n):
    for j in range(n):
        for k in range(n):
            if i < j < k and s[i] == 'Q' and s[j] == 'A' and s[k] == 'Q':
                a += 1
                
print(a)