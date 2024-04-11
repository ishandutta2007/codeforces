x = int(input())
print((x // 7) * 2 + max(0, (x % 7 - 5)), (x // 7) * 2 + min(2, x % 7))