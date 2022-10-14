s = input()
print(max(0, min(s.count('a') * 2 - 1, len(s))))