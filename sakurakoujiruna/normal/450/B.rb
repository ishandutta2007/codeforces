x, y = gets.split.map { |x| x.to_i }
n = gets.to_i

Mod = 1e9.to_i + 7
n = n % 6 + 6
3.upto(n) do
	x, y = y, y - x
end
puts (y % Mod + Mod) % Mod