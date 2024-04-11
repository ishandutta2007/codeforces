n = int(input())
s = 'aeiou'
lol = 'aeiou'
for i in range(5, n // 5 + 1):
    if n % i == 0:
        a = i
        b = n // i
        if a >= 5 and b >= 5:
            s = s * (a // 5) + 'aeiou'[:a % 5]
            for j in range(b):
                print(s, end='')
                s = s[1:] + s[0]
            exit(0)
print(-1)