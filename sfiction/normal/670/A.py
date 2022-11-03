n = int(raw_input())
print n / 7 * 2 + max(0, n % 7 - 5), n / 7 * 2 + min(n % 7, 2)