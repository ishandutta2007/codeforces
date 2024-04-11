n, m = map(int, input().split())
cnt = 0
while n != m:
    if m % 2 or n > m:
        m += 1
    else:
        m //= 2
    cnt += 1
print(cnt)