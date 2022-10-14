def find(n):
    cnt = 0
    if n < 10:
        return cnt+n
    cnt += n % 10 + 10
    if n % 10 == 9:
        cnt -= 10
        return cnt + find(n//10)
    return cnt + find(n//10-1)


print(find(int(input())))